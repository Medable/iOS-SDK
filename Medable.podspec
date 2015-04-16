# Medable.podspec

Pod::Spec.new do |s|
    s.name             = "Medable"
    s.version          = "0.9.2"
    s.summary          = "Medable iOS SDK."
    s.description      = <<-DESC
            Medable is a cloud platform that provides HIPAA-compliant services to mobile
            and web applications. Using this iOS SDK, you can build applications that
            communicate securely with Medable’s cloud platform to incorporate Medable
            capabilities into your application.
                        DESC
    s.homepage         = "https://github.com/Medable/iOS-SDK"
    s.license          = 'BSD 3-clause'
    s.author           = { "Medable Inc." => "hello@medable.com" }
    s.source           = { :git => "https://github.com/Medable/iOS-SDK.git", :tag => s.version.to_s }
    s.social_media_url = 'https://twitter.com/medableinc'

    s.platform     = :ios, '7.0'
    s.requires_arc = true

    s.ios.vendored_frameworks = 'iOSMedableSDK/iOSMedableSDK.framework'

    s.public_header_files = 'iOSMedableSDK/iOSMedableSDK.framework/Headers/*.h'
    s.frameworks = 'ImageIO', 'SystemConfiguration', 'CoreText', 'MobileCoreServices', 'QuartzCore', 'CoreLocation','CFNetwork','CoreGraphics'
end
