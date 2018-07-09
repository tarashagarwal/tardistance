class TarDistance
	require_relative '../../ext/skynet/skynet'
	include PercentSearch
	def self.percent_change(search_string,search_array,percent_diff)
		if search_array.kind_of?(Array) and search_string.kind_of(String) and percent_diff.is_a?(Numeric)
			return distance(search_string,search_array,percent_diff)
		else
			raise "Invalid Parameters please pass percent_change(string,array,decimal)"
		end
	end
end