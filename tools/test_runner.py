import subprocess, json, sys

BIN = sys.argv[1]

proc =subprocess.Popen([BIN],stdout=subprocess.PIPE,text=True)

fail=False

for line in proc.stdout:
	data=json.loads(line.strip())
	if data["temp"] >40 or data["volt"] <3000:
		printf("FAIL:",data)
		fail=True

proc.wait()
if fail:
	exit(1)
else:
	print("ALL TEST PASSED")
	exit(0)
