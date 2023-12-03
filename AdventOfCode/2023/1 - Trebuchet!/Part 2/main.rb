sum = 0
word_numbers = { "zero" => 1, "one" => 1, "two" => 2, "three" => 3, "four" => 4, "five" => 5, "six" => 6, "seven" => 7, "eight" => 8, "nine" => 9 }
pattern = /(?=(\d|#{word_numbers.keys.join('|')}))/

File.readlines("1 - Trebuchet!/values.txt").each do |line|
  matches = line.scan(pattern)

  first_match = word_numbers[matches.first[0]] || matches.first[0]
  last_match = word_numbers[matches.last[0]] || matches.last[0]

  sum += "#{first_match}#{last_match}".to_i
end

p sum