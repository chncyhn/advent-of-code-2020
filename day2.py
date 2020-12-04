p1 = 0
p2 = 0
with open("data2.txt", "r") as fd:
	for line in fd.readlines():
		cmds = line.split(" ")
		lo, hi = map(int, cmds[0].split("-"))
		token = cmds[1].rstrip(":")

		cnt1 = sum(c == token for c in cmds[-1])
		cnt2 = (cmds[-1][lo-1] == token) + (cmds[-1][hi-1] == token)

		p1 += (lo <= cnt1 <= hi)
		p2 += (cnt2 == 1)
print(p1, p2)
