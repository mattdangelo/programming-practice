counts = []
current = 0

File.readlines("1 - Calorie Counting/values.txt").each do |line|
  if line == "\n"
    counts << current
    current = 0
  else
    current += line.to_i
  end
end

pp counts.max(3).sum
