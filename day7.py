def connected(s, t, graph):
	if s == t:
		return True
	return any(connected(c[1], t, graph) for c in graph[s])

def bag_count(sc, graph):
	return sc[0] * (1 + sum(bag_count(c, graph) for c in graph[sc[1]]))

def read_graph():
	graph = {}
	with open("data7.txt", "r") as fd:
		lines = [f.split(" ") for f in fd.readlines()]
		for words in lines:
			col = words[0] + " " + words[1]
			children = []
			for i in range(4, len(words), 4):
				cnt = 0 if words[i] == "no" else int(words[i])
				if cnt == 0:
					break
				children.append((cnt, words[i+1] + " " + words[i+2]))
			graph[col] = children
	return graph

graph = read_graph()
sg = "shiny gold"
p1 = sum(connected(node, sg, graph) for node in set(graph) - {sg})
p2 = bag_count((1, "shiny gold"), graph) - 1
print(p1, p2)	
