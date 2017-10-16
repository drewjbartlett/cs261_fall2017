# The Dynamic Array Class
# Python has all kinds of powerful stuff that does what your dynamic array needs to do
# No, you CAN'T use any of that
class DynamicArray(object):

    INIT_CAPACITY = 2^4
    RESIZE_MULTIPLIER = 2

    # The __init__ function is run when you instantiate an instance of this object
    def __init__(self):

        # variables beginning with the underscore can denote internal or self referential data
        # That isn't strictly enforced, but merely a nice convention for readability
        self._size = 0
        self._capacity = DynamicArray.INIT_CAPACITY
        self._data = [None] * self._capacity

    #################################
    ## DO YOUR WORK BELOW THIS LINE #
    #################################

    # Return the size of the dynamic array
    def size(self):
        #TODO: return the size of the dynamic array this class represents
        return self._size

    # Return the capacity of the dynamic array
    def capacity(self):
        # TODO: return the capacity of the dynamic array this class represents
        return self._capacity

    # Add an element to the end of the dynamic array
    def add(self, value):
        #TODO: add the passed value to the dynamic array

        # resize the array
        self._resize()

        self.put(self.size(), value)

        return 1

    # Get the value at the position passed in as a parameter
    def get(self, pos):
        #TODO: return the value currently stored at the passed position
        return self._data[pos]

    # Put a value into the dynamic array at the specified position, overwriting what was there
    def put(self, pos, value):
        #TODO: put the passed value into the dynamic array at the passed position

        # if the pos is None and the value is not None
        # then it's clear that you're adding
        if (self.get(pos) is None and value is not None):
            self._size += 1

        # set the value
        self._data[pos] = value;

        return 1

    # Swap 2 specified values in the dynamic array
    def swap(self, pos1, pos2):
        #TODO: swap the values at the 2 passed positions with one another

        # cache pos1 value
        pos1_value = self.get(pos1)

        # set pos1 to pos2
        # not using put here because it will mess up the size
        self._data[pos1] = self.get(pos2)

        # set pos2 to pos1_value
        # not using put here because it will mess up the size
        self._data[pos2] = pos1_value

        return 1

    # Remove a value from the dynamic array (and return it)
    def remove(self, pos):
        #TODO: remove the value found at the passed pos and return it

        value = self.get(pos)

        self.put(pos, None)

        if (self.size() > 0):
            self._size -= 1

        # if it's the last item in the array, don't reshift it
        if pos != self.size():
            # loop from pos to end of array
            for i in range(pos, self.capacity() - 1):
                # move None to end
                self.swap(i, i + 1)

        return value

    # Resize the underlying array to make room
    def _resize(self):
        #TODO: resize the underlying array according to certain rules to make room for more values

        if self.size() == self.capacity():

            # make the new capacity
            self._capacity = self.capacity() * DynamicArray.RESIZE_MULTIPLIER

            # make the new array
            new_data = [None] * self.capacity()

            # fill it with current array values
            for i in range(self.size()):
                new_data[i] = self.get(i)

            # replace data with it
            self._data = new_data

        return 1

    # DO NOT MODIFY THIS PRINT
    # Print the data in a useful way
    def print_data(self):
        print "[ %s ]" % ' | '.join([str(v) for v in self._data])
