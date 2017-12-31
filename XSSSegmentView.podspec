Pod::Spec.new do |s|
  s.name         = "XSSSegmentView"
  s.version      = "1.0.0"
  s.summary      = "XSSSegmentView is Self defined Segment Controll. This is a modified version of the original Pod made by xushsh163."
  s.homepage     = "https://github.com/xushsh163/XSSSegmentView.git"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "xushsh163" => "xushsh163@163.com" }
  s.platform     = :ios, "6.0"
  s.source       = { :git => "https://github.com/xushsh163/XSSSegmentView.git",
                     :tag => s.version.to_s }
  s.source_files  = "XSSSegmentView/*.{h,m}"
  s.frameworks = "Foundation", "UIKit"
  s.requires_arc = true
  s.pod_target_xcconfig = { 'SWIFT_VERSION' => '3.0' }
end
