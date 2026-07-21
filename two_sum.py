arr = []
n = int(input("Enter the number of elements in the array: "))
for i in range(n):
    element = int(input(f"Enter element {i + 1}: "))
    arr.append(element)

target = int(input("Enter the target sum: "))
def two_sum(arr, target):
    num_to_index = {}
    for index, num in enumerate(arr):
        complement = target - num
        if complement in num_to_index:
            return [num_to_index[complement], index]
        num_to_index[num] = index
    return []
result = two_sum(arr, target)
if result:
    print(f"Indices of the two numbers that add up to {target} are: {result}")
else:
    print("No two numbers add up to the target sum.")


    



