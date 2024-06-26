Pod::Spec.new do |spec|
spec.name         = "OpenAdx"
spec.version      = "1.0.3"
spec.summary      = "OpenAdx广告平台"
spec.description  = <<-DESC
OpenAdx,广告SDK,自有直客广告主
DESC
spec.homepage     = "https://github.com/konnitiha/OpenAdxSDK.git"
spec.license      = { :type => "MIT", :file => "LICENSE" }
spec.author             = { "cloooud" => "1053591151@qq.com" }
spec.source       = { :git => "https://github.com/konnitiha/OpenAdxSDK.git", :tag => spec.version }
spec.platform     = :ios, '12.0'
spec.ios.deployment_target = '12.0'
spec.requires_arc = true
spec.frameworks = ["Foundation", "UIKit", "MobileCoreServices", "CoreGraphics", "Security", "SystemConfiguration", "CoreTelephony", "AdSupport", "StoreKit", "AVFoundation", "MediaPlayer", "CoreMedia", "WebKit", "Accelerate", "CoreLocation", "AVKit", "CoreMotion"]
spec.source_files = "OpenAdxSDK/**/*"
spec.resources = ['OpenAdxSDK/OpenAdxSDK.bundle']
spec.user_target_xcconfig =   {'OTHER_LDFLAGS' => ['-lObjC']}
spec.libraries = ["z", "resolv.9", "sqlite3", "c++", "c++abi", "resolv"]
valid_archs = ['x86_64', 'arm64']
spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 arm64' }
#spec.default_subspecs = 'OpenAdxSDK'
#spec.ios.vendored_frameworks = 'OpenAdxSDK/OpenAdx.framework'
spec.dependency 'Protobuf'

end
