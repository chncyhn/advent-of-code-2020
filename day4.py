import re

def read_input():
	pps = []
	with open("data4.txt", "r") as fd:
		cur_fields = {}
		for line in fd.readlines() + ["\n"]:
			line = line.strip()
			if line != "":
				fields = line.split(" ")
				cur_fields.update( dict(f.split(":") for f in fields))
			else:
				pps.append(cur_fields)
				cur_fields = {}
	return pps

REQ = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"}
VALIDATIONS = {
	"byr": lambda x: x.isnumeric() and len(x) == 4 and 1920 <= int(x) <= 2002,
	"iyr": lambda x: x.isnumeric() and len(x) == 4 and 2010 <= int(x) <= 2020,
	"eyr": lambda x: x.isnumeric() and len(x) == 4 and 2020 <= int(x) <= 2030,
	"hgt": lambda x: (re.fullmatch(r"\d\d\dcm", x) is not None and 150 <= int(x.replace("cm", "")) <= 2193) \
				  or (re.fullmatch(r"\d\din", x) is not None and 59 <= int(x.replace("in", "")) <= 76),
	"hcl": lambda x: re.fullmatch(r"#[0-9a-f]{6}", x) is not None,
	"ecl": lambda x: x in {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"},
	"pid": lambda x: x.isnumeric() and len(x) == 9,
}
p1, p2 = 0, 0
for passport in read_input():
	p1 += all(r in passport for r in REQ)
	p2 += sum(VALIDATIONS.get(f, lambda x : False)(v) for f, v in passport.items()) == 7
print(p1, p2)
