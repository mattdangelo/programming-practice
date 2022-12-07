WINDOW_LENGTH = 4

data = File.read("6 - Tuning Trouble/values.txt")

window = {}

def add_to_window(c, in_window)
  in_window.key?(c) ? in_window[c] += 1 : in_window[c] = 1
end

def remove_from_window(c, in_window)
  in_window[c] == 1 ? in_window.delete(c) : in_window[c] -= 1
end

left = 0
right = 0

# Initial characters
while right - left < WINDOW_LENGTH do
  add_to_window(data[right], window)
  right += 1
end

while window.size < WINDOW_LENGTH do
  remove_from_window(data[left], window)
  add_to_window(data[right], window)
  left += 1
  right += 1
end

p right