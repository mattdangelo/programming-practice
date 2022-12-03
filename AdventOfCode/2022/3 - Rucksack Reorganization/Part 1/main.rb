def char_to_ord(char)
  char.ord - (char == char.upcase ? 38 : 96)
end

def ord_same_item(string)
  first, second = string.chars.each_slice(string.length / 2).map(&:join)
  intersecting_char = (first.split('') & second.split(''))[0]
  char_to_ord(intersecting_char)
end

p File.readlines("3 - Rucksack Reorganization/values.txt").sum { |line| ord_same_item(line) }