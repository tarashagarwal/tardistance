
Gem::Specification.new do |s|
  s.name        = 'tardistance'
  s.version     = '0.0.0'
  s.date        = '2018-07-13'
  s.summary     = "A fast method to filter strings"
  s.description = "Filter strings on basis of percentage of changes to be made in the string in terms of levenshtein distance by string length"
  s.authors     = ["Tarash Agarwal"]
  s.email       = 'tarash.agarwal@gmail.com'
  s.files       = Dir.glob('lib/**/*.rb') + Dir.glob('ext/**/*.c')
  s.homepage    = 'https://github.com/tarashagarwal/tardistance.git'
  s.license     = 'MIT'
  s.platform    = Gem::Platform::RUBY
  s.metadata    ={
    "authors_blog" => "https://tarashagarwal.github.io/",
    "levenshtein distance algorithm" => "https://en.wikipedia.org/wiki/Levenshtein_distance",
  }
  s.extensions   = 'ext/tardistance/extconf.rb'
end