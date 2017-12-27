# Medable.podspec

Pod::Spec.new do |s|
    s.name             = "Medable"
    s.version          = "1.9.16"
    s.summary          = "Medable Cortex iOS SDK."
    s.description      = <<-DESC
            Medable is a cloud platform that provides HIPAA-compliant services to mobile
            and web applications. Using this iOS SDK, you can build applications that
            communicate securely with Medable’s cloud platform to incorporate Medable
            capabilities into your application.
                        DESC
    s.homepage         = "https://github.com/Medable/iOS-SDK"
    s.license          = { :type => 'BSD 3-clause', :file => 'LICENSE' }
    s.author           = { "Medable Inc." => "hello@medable.com" }
    s.source           = { :git => "https://github.com/Medable/iOS-SDK.git", :tag => s.version.to_s }
    s.source_files     = 'Cortex/Medable.framework/Headers/*.h'
    s.social_media_url = 'https://twitter.com/medableinc'

    s.platform     = :ios, '7.0'
    s.requires_arc = true
    s.xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }

    s.ios.vendored_frameworks = 'Cortex/Medable.framework'

    s.public_header_files = 'Cortex/Medable.framework/Headers/M*.h'
    s.frameworks = 'ImageIO', 'SystemConfiguration', 'CoreText', 'MobileCoreServices', 'QuartzCore', 'CoreLocation','CFNetwork','CoreGraphics'
end
