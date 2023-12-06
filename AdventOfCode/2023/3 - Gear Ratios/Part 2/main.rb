def surrounding_cogs(gear_locations, line_index, start_index, end_index)
  res = []

  res << { x: line_index, y: end_index + 1 } if gear_locations[line_index]&.include?(end_index + 1)
  res << { x: line_index, y: start_index - 1 } if gear_locations[line_index]&.include?(start_index - 1)

  ((start_index - 1)..(end_index + 1)).each do |i|
    res << { x: line_index - 1, y: i } if gear_locations[line_index - 1]&.include?(i)
  end

  ((start_index - 1)..(end_index + 1)).each do |i|
    res << { x: line_index + 1, y: i } if gear_locations[line_index + 1]&.include?(i)
  end

  res
end

pattern = /\b\d+\b/
numbers = []
gear_locations = {}

File.readlines("3 - Gear Ratios/values.txt").each_with_index do |line, idx|
  matches = line.enum_for(:scan, pattern).map { Regexp.last_match }

  matches.each do |match|
    numbers << { line_index: idx, start_index: match.begin(0), end_index: match.end(0) - 1, number: match.to_s.to_i }
  end

  line.each_char.with_index do |char, char_idx|
    if char == '*'
      if gear_locations.key?(idx)
        gear_locations[idx].add(char_idx)
      else
        gear_locations[idx] = Set.new([char_idx])
      end
    end
  end
end

gear_numbers = {}
numbers.each do |num_details|
  surrounding = surrounding_cogs(gear_locations, num_details[:line_index], num_details[:start_index], num_details[:end_index])
  surrounding.each do |coord|
    if gear_numbers.key?(coord)
      gear_numbers[coord] << num_details[:number]
    else
      gear_numbers[coord] = [num_details[:number]]
    end
  end
end

sum = 0

gear_numbers.each do |_, value|
  sum += value.first * value.last if value.size == 2
end

p sum