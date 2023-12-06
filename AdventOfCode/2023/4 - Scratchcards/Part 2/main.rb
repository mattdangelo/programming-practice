section_delimiters = /[:|\n]+/

# Populate the scratchcards array
scratchcards = []
File.readlines("4 - Scratchcards/values.txt").each.with_index do |line, idx|
  scratchcards << line.split(section_delimiters)
end

# Initialize the count of all the scratchcards with 1
card_counts = {}
scratchcards.size.times do |i|
  card_counts[i] = 1
end

# Play out the scenario
scratchcards.each.with_index do |card, idx|
  overlapping_numbers_count = (card[1].split(' ') & card[2].split(' ')).count
  overlapping_numbers_count.times do |i|
    card_counts[idx + i + 1] += card_counts[idx]
  end
end

p card_counts.values.sum