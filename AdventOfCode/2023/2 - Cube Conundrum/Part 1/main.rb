game_group_delimiters = /[:;\n]+/
inter_game_delimiters = /[,\s]+/
sum = 0
limits = { 'green' => 13, 'red' => 12, 'blue' => 14 }

File.readlines("2 - Cube Conundrum/values.txt").each do |line|
  tokens = line.split(game_group_delimiters)
  id = tokens[0].split(' ')[1].to_i
  game_possible = true
  tokens.drop(1).each do |game|
    game.strip.split(inter_game_delimiters).each_slice(2) do |count, colour|
      if count.to_i > limits[colour]
        game_possible = false
        break
      end
    end
  end

  sum += id if game_possible
end

p sum