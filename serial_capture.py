#!/usr/bin/env python2.6

import sys
import os
import serial
import time

def new_file():
	return file(os.path.join("runs",time.strftime("%Y-%m-%d %H%M%S")+".csv"), "wt")

def run():
	try:
		fout = None
		try:
			fout = new_file()
		except:
			print "No file!"
		ser = serial.Serial( port=sys.argv[ 1 ], baudrate=230400, bytesize=serial.EIGHTBITS, stopbits=serial.STOPBITS_TWO, timeout=0 )
		count = 0
		while True:
			ch = ser.read()
			if len( ch ) == 0:
				time.sleep( 0.001 )
				continue
			if ch == "\n":
				if fout:
					fout.flush()

			if fout:
				fout.write(ch)
			sys.stdout.write(ch)

	except KeyboardInterrupt:
		print 'Exiting...'

if __name__ == '__main__':
	run()
