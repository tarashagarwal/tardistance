require "rake/extensiontask"
require 'fileutils'

EXT = RbConfig::CONFIG['DLEXT']
Rake::ExtensionTask.new "tardistance" do |ext|
	Dir.chdir('ext/tardistance') do
	    ruby "extconf.rb"
	    sh "make"
  	end
	FileUtils.mkdir_p('lib/tardistance')
  	cp "ext/tardistance/tardistance.#{EXT}", "lib/tardistance/tardistance.#{EXT}"
end