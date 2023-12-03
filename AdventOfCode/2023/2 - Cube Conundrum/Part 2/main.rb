game_group_delimiters = /[:;\n]+/
inter_game_delimiters = /[,\s]+/
sum = 0

File.readlines("2 - Cube Conundrum/values.txt").each do |line|
  tokens = line.split(game_group_delimiters)
  min_colours = {}
  tokens.drop(1).each do |game|
    game.strip.split(inter_game_delimiters).each_slice(2) do |count, colour|
      if !min_colours.key?(colour) || (min_colours.key?(colour) && min_colours[colour] < count.to_i)
        min_colours[colour] = count.to_i
      end
    end
  end

  game_power = 1
  min_colours.each_value { |v| game_power *= v }
  sum += game_power
end

p sum