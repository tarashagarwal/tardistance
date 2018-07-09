
Gem::Specification.new do |s|
  s.name        = 'tardistance'
  s.version     = '1.0.0'
  s.date        = '2018-06-24'
  s.summary     = "A fast implemention to select stings based on levenshtein distance algorithm"
  s.description = "A gem to select strings from a given array having a particualar percentage distance(levenshtein distance) from a given string. Primarily built for search suggestion can be used for other applications."
  s.authors     = ["Tarash Agarwal"]
  s.email       = 'tarash.agarwal@gmail.com'
  s.files       = ["lib/tardistance.rb"]
  s.homepage    ='https://github.com/tarashagarwal/tardistance.git'
  s.license       = 'MIT'
  s.metadata ={
    "authors_blog" => "https://tarashagarwal.github.io/",
    "levenshtein distance algorithm" => "https://en.wikipedia.org/wiki/Levenshtein_distance",
  }
  s.extensions = %w[ext/skynet/extconf.rb]
end