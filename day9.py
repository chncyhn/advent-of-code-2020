from collections import Counter
from itertools import accumulate

with open("data9.txt") as fd:
	nums = list(map(int, fd.readlines()))

PREAMBLE = 25
n = len(nums)
cnts = Counter([nums[i]+nums[j] for i in range(PREAMBLE) for j in range(i+1, PREAMBLE)])
p1 = -1
for i in range(PREAMBLE, n):
	r = i - PREAMBLE
	if cnts[nums[i]] <= 0:
		p1 = nums[i]
		break
	cnts -= Counter([nums[r]+nums[j] for j in range(r+1, r+PREAMBLE)])
	cnts += Counter([nums[i]+nums[j] for j in range(r+1, r+PREAMBLE)])

acc = {v: i for i, v in enumerate(accumulate(nums))}
tot = sum(nums[:PREAMBLE])
p2 = -1
for i in range(PREAMBLE, n):
	tot += nums[i]
	if tot - p1 in acc:
		lo, hi = acc[tot-p1], i
		p2 = max(nums[lo:hi]) + min(nums[lo:hi])
		break
print(p1, p2)
