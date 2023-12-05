def has_surrounding_symbol?(symbol_locations, line_index, start_index, end_index)
  return true if symbol_locations[line_index]&.include?(end_index + 1) || symbol_locations[line_index]&.include?(start_index - 1)

  ((start_index - 1)..(end_index + 1)).step(1) do |i|
    return true if symbol_locations[line_index - 1]&.include?(i)
  end

  ((start_index - 1)..(end_index + 1)).step(1) do |i|
    return true if symbol_locations[line_index + 1]&.include?(i)
  end

  false
end

sum = 0
pattern = /\b\d+\b/
numbers = []
symbol_locations = {}

File.readlines("3 - Gear Ratios/values.txt").each_with_index do |line, idx|
  matches = line.enum_for(:scan, pattern).map { Regexp.last_match }

  matches.each do |match|
    numbers << { line_index: idx, start_index: match.begin(0), end_index: match.end(0) - 1, number: match.to_s.to_i }
  end

  line.each_char.with_index do |char, char_idx|
    unless char.match?(/[0-9.\n\r]/)
      if symbol_locations.key?(idx)
        symbol_locations[idx].add(char_idx)
      else
        symbol_locations[idx] = Set.new([char_idx])
      end
    end
  end
end

numbers.each do |num_details|
  if has_surrounding_symbol?(symbol_locations, num_details[:line_index], num_details[:start_index], num_details[:end_index])
    sum += num_details[:number]
  end
end

pp sum