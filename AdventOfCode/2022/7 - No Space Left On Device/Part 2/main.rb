UPDATE_MIN_DISK_SPACE = 30000000
DISK_SIZE = 70000000

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
$directory_sizes = []

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

  $directory_sizes << root.size

  root.size
end

dfs(root)

min_deletion_size = UPDATE_MIN_DISK_SPACE - (DISK_SIZE - root.size)

p $directory_sizes.sort.find { |s| s >= min_deletion_size }