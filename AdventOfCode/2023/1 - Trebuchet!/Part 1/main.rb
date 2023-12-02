sum = 0

File.readlines("1 - Trebuchet!/values.txt").each do |line|
  first_char = nil; last_char = nil
  line.each_char do |c|
    if c =~ /[0-9]/
      if first_char.nil?
        first_char = c
      end
      last_char = c
    end
  end
  sum += "#{first_char}#{last_char}".to_i
end

p sum