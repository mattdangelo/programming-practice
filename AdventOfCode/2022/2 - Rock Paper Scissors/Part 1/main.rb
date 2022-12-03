WIN_POINTS = 6
DRAW_POINTS = 3
LOSE_POINTS = 0

SHAPE_SCORE = { 'X' => 1, 'Y' => 2, 'Z' => 3, 'A' => 1, 'B' => 2, 'C' => 3 }.freeze
GAME_SCORE = { 'A' => { 'Y' => WIN_POINTS,  'Z' => LOSE_POINTS },
               'B' => { 'X' => LOSE_POINTS, 'Z' => WIN_POINTS },
               'C' => { 'X' => WIN_POINTS,  'Y' => LOSE_POINTS } }.freeze

def strategy_score(them, you)
  if SHAPE_SCORE[you] == SHAPE_SCORE[them]
    3
  else
    GAME_SCORE[them][you]
  end
end

def game_score(them, you)
  SHAPE_SCORE[you] + strategy_score(them, you)
end

pp File.readlines("2 - Rock Paper Scissors/values.txt").sum { |line| game_score(line[0], line[2]) }
