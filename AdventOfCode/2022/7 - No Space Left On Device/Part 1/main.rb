MIN_DIRECTORY_SIZE = 100000

class Node
  attr_accessor :directories, :files, :size

  def initialize
    @size = 0
    @files = {}
    @directories = {}
  end
end

root = Node.new
path = [root]
$min_directory_size_sum = 0

# Construct tree
File.readlines("7 - No Space Left On Device/values.txt").each do |line|
  tokens = line.split
  if tokens[0] == '$'
    if tokens[1] == 'cd'
      if tokens[2] == '/'
        path = [root]
      elsif tokens[2] == '..'
        path.pop
      else
        path << path.last.directories[tokens[2]]
      end
    elsif tokens[1] == 'ls'
      next
    end
  elsif tokens[0] == 'dir'
    path.last.directories[tokens[1]] = Node.new
  else
    path.last.files[tokens[1]] = tokens[0]
  end
end

def dfs(root)
  children_size = root.directories.values.sum { |child| dfs(child) }
  root.size = children_size + root.files.sum { |f| f.last.to_i }

  # Add directory size to total if it's small enough
  $min_directory_size_sum += root.size if root.size <= MIN_DIRECTORY_SIZE

  root.size
end

dfs(root)

p $min_directory_size_sum