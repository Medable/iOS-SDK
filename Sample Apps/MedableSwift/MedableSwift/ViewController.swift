//
//  ViewController.swift
//  MedableSwift
//
//  Copyright (c) 2015 Medable Inc. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet var orgName : UIKit.UILabel?
    @IBOutlet var status : UIKit.UILabel?
    @IBOutlet var orgCode : UIKit.UILabel?
    
    override func viewDidLoad()
    {
        super.viewDidLoad()
        
        self.orgName?.text = ""
        self.orgCode?.text = ""
        
        let client = MDAPIClient.sharedClient()
        
        if let client = client
        {
            self.status?.text = "Initialized"
        }
        else
        {
            self.status?.text = "Error on Init"
        }
    }

    @IBAction func getOrganization(sender: AnyObject)
    {
        let client = MDAPIClient.sharedClient()
        
        client.getOrgInfoWithCallback { ( org: MDOrg?, fault: MDFault?) -> Void in
            
            if let org = org
            {
                self.orgName?.text = org.name
                self.orgCode?.text = org.code
                self.status?.text = "Ok"
            }
            else
            {
                self.status?.text = "Error"

                if let fault = fault
                {
                    var alert : UIKit.UIAlertController = UIAlertController()
                    alert.title = "Error"
                    alert.message = fault.message
                    
                    let cancelAction = UIAlertAction(title: "Ok", style: .Cancel) { (action) in
                    }
                    alert.addAction(cancelAction)
                    
                    self.presentViewController(alert, animated: true, completion: { () -> Void in
                        
                    })
                }
            }
        }
    }

}

