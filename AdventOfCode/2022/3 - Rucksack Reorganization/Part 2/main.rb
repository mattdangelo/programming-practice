def char_to_ord(char)
  char.ord - (char == char.upcase ? 38 : 96)
end

def ord_same_item(buffer)
  intersecting_char = (buffer.map { |s| s.split('') }.inject(&:&))[0]
  char_to_ord(intersecting_char)
end

p File.readlines("3 - Rucksack Reorganization/values.txt").each_slice(3).sum { |lines| ord_same_item(lines) }
