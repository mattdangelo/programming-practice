current = 0
best = 0

File.readlines("1 - Calorie Counting/values.txt").each do |line|
  if line == "\n"
    best = [best, current].max
    current = 0
  else
    current += line.to_i
  end
end

pp [best, current].max
