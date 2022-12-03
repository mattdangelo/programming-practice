WIN_POINTS = 6
DRAW_POINTS = 3
LOSE_POINTS = 0

SHAPE_SCORE = { 'X' => 1, 'Y' => 2, 'Z' => 3, 'A' => 1, 'B' => 2, 'C' => 3 }.freeze

MY_SHAPE = { 'A' => { 'X' => 'Z', 'Y' => 'X', 'Z' => 'Y' },
             'B' => { 'X' => 'X', 'Y' => 'Y', 'Z' => 'Z' },
             'C' => { 'X' => 'Y', 'Y' => 'Z', 'Z' => 'X' } }.freeze

def strategy_score(result)
  case(result)
  when 'X'
    LOSE_POINTS
  when 'Y'
    DRAW_POINTS
  when 'Z'
    WIN_POINTS
  end
end

def game_score(them, result)
  my_shape = MY_SHAPE[them][result]
  SHAPE_SCORE[my_shape] + strategy_score(result)
end

pp File.readlines("2 - Rock Paper Scissors/values.txt").sum { |line| game_score(line[0], line[2]) }
