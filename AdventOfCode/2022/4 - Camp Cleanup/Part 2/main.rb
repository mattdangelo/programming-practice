def partly_overlaps(string)
  r1, r2 = string.split(',').map { |r| r.split('-').map(&:to_i) }
  r2[0] <= r1[1] && r1[0] <= r2[1]
end

p File.readlines("4 - Camp Cleanup/values.txt").count { |line| partly_overlaps(line) }
