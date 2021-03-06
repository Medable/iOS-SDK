//
//  ViewController.swift
//  MedableSwift
//
//  Copyright (c) 2015 Medable Inc. All rights reserved.
//

import UIKit

class ViewController: UIViewController
{
    @IBOutlet var orgName : UIKit.UILabel?
    @IBOutlet var status : UIKit.UILabel?
    @IBOutlet var orgCode : UIKit.UILabel?
    
    override func viewDidLoad()
    {
        super.viewDidLoad()
        
        self.orgName?.text = ""
        self.orgCode?.text = ""
        
        self.status?.text = "Initialized"
    }

    @IBAction func getOrganization(_ sender: AnyObject)
    {
        let client = Medable.client()
        
        client.getPublicOrgInfo(
            callback: { (orgInfo, fault) -> Void in
                
                if let orgInfo = orgInfo
                {
                    self.orgName?.text = orgInfo["name"] as? String
                    self.orgCode?.text = orgInfo["code"] as? String
                    self.status?.text = "Ok"
                }
                else
                {
                    self.status?.text = "Error"
                    
                    if let fault = fault
                    {
                        let alert = UIAlertController()
                        alert.title = "Error"
                        alert.message = fault.message
                        
                        let cancelAction = UIAlertAction(title: "Ok", style: .cancel) { (action) in
                        }
                        alert.addAction(cancelAction)
                        
                        self.present(alert, animated: true, completion: { () -> Void in
                            
                        })
                    }
                }
            })
    }
}

