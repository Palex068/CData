#!/usr/bin/env python

import sys

from PySide2.QtWidgets import QApplication, QLabel

app = QApplication(sys.argv)
label = QLabel("<font color=red size=40>Hello World!</font>")

label.show()
label.show()
app.exec_()
