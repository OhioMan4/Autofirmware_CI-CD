import subprocess
import json
import sys

DEVICE_ID= "DEV001"

print("[INFO] Running firmware...")
proc =subprocess.run(
	["./firmware/firmware_bin"],
	capture_output=True,
	text=True
)

if proc.returncode !=0:
	print("[FAIL] firmware execution failed")
	sys.exit(1)

lines = proc.stdout.strip().splitlines()

if not lines:
	print("[FAIL] No output from firmware")
	sys.exit(1)

for idx, line in enumerate(lines):
	try:
		data=json.loads(line)
	except json.JSONDecodeError:
		print(f"[FAIL] Invalid JSON at line {idx}: {line}")
		sys.exit(1)
	if data.get("device") != DEVICE_ID:
		print("[FAIl] Wrong device ID")
		sys.exit(1)

	temp =data.get("temp")
	volt =data.get("volt")
	if not (20 <= temp <=34):
		print(f"[FAIL] Temperature out of range: {temp}")
		sys.exit(1)
	if not (3300 <= volt <= 3499):
		print(f"[FAIL] Voltage out of range: {volt}")
		sys.exit(1)

print("Output test passed ! ")
		
