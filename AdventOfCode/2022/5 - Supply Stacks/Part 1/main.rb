moves = []
stacks = {}
column_map = {}

def parse_input!(file, moves, stacks, column_map)
  File.readlines(file).each do |line|
    if line[0] == 'm'
      # Move line
      moves << line.scan(/\d+/)
    elsif line.include?("[")
      # Initial stack definition
      line.chars.each_with_index do |c, idx|
        ((stacks[idx] ||= []) << c) if c =~ /[A-Z]/
      end
    elsif line[0] == ' ' && line.length != 0
      # Index Line
      line.chars.each_with_index do |c, idx|
        column_map[c] = idx if c.match?(/[[:digit:]]/)
      end
    end
  end

  stacks.transform_values!(&:reverse)
end

parse_input!("5 - Supply Stacks/values.txt", moves, stacks, column_map)

moves.each do |m|
  m[0].to_i.times { |_| stacks[column_map[m[2]]] << stacks[column_map[m[1]]].pop }
end

p stacks.sort.to_h.values.map(&:last).join('')