#########################################################################################
# Here you need to write some basic tests to make sure your Stack implementation runs correctly
# You can run them by running 'python StackTests.py' from the command line
#########################################################################################

from Stack import Stack

stack = Stack()

print "Checking basic variable initializations..."

# TODO: tests here

assert stack._size == stack.size()

stack.push(1)

assert stack.size() == 1

stack.print_stack()
print "done\n"

###################################

print "Checking is_empty and size..."

# TODO: tests here

assert stack.is_empty() == False

stack.pop()

assert stack.is_empty() == True

assert stack.size() == 0

for i in range(5):
    stack.push(i)

assert stack.size() == 5
assert stack.is_empty() == False

stack.print_stack()
print "done\n"

###################################

print "Checking push, top..."

# TODO: tests here

# make a new stack
stack = Stack()

stack.push(0)

assert stack.top() == 0

for i in range(5):
    stack.push(i)

assert stack.top() == 4
stack.pop()

assert stack.top() == 3

# make a new stack
stack = Stack()

for i in range(5):
    stack.push(i)

for i in range(stack.size() - 1, -1, -1):
    assert stack.top() == i
    stack.pop()

stack.print_stack()
print "done\n"

###################################

print "Checking pop..."

# TODO: tests here

stack = Stack()

stack.push(6)
stack.push(7)
stack.push(8)

assert stack.pop() == 8
assert stack.size() == 2

assert stack.pop() == 7
assert stack.size() == 1

stack.push(15)
stack.push(20)
stack.push(25)

assert stack.pop() == 25
assert stack.size() == 3

assert stack.pop() == 20
assert stack.size() == 2

assert stack.pop() == 15
assert stack.size() == 1

assert stack.pop() == 6
assert stack.size() == 0
assert stack.is_empty() == True

stack.print_stack()
print "done\n"

###################################

stack.print_stack()
print "All checks passed"
