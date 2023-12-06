section_delimiters = /[:|\n]+/

points = 0

File.readlines("4 - Scratchcards/values.txt").each do |line|
  sections = line.split(section_delimiters)
  overlapping_numbers_count = (sections[1].split(' ') & sections[2].split(' ')).count

  if overlapping_numbers_count > 0
    points += 2 ** (overlapping_numbers_count - 1)
  end
end

p points
