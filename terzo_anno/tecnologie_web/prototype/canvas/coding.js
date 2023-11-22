//! Canvas 2D Context
//! Prototyping

///
/// UNO
///

const uno = document.getElementById('uno')
const ctx_uno = uno.getContext('2d')

ctx_uno.beginPath() // start a brand new path
// ctx_uno.moveTo(x, y)
ctx_uno.moveTo(100, 50) // move the pen to (x, y)
ctx_uno.lineTo(150, 25) // draw a line to (150, 25)
ctx_uno.lineTo(200, 50) // draw a line to (200, 50)
ctx_uno.lineTo(200, 100)
ctx_uno.lineTo(100, 100)
ctx_uno.lineTo(100, 50)
ctx_uno.stroke()

ctx_uno.beginPath() // start a brand new path
ctx_uno.arc(130, 100, 30, Math.PI, Math.PI * 2) // draw a circle
// (center_x, certer_y, radius, starting_angle, ending_angle)
ctx_uno.stroke()	// draw the path

ctx_uno.beginPath()
ctx_uno.rect(125, 75, 10, 25) // draw a rectangle
// (x, y, width, height)
ctx_uno.stroke()

ctx_uno.beginPath()
ctx_uno.moveTo(130, 70)
ctx_uno.lineTo(200, 70)
ctx_uno.stroke()


///
/// DUE
///

const due = document.getElementById('due')
const ctx_due = due.getContext('2d')

ctx_due.beginPath()
ctx_due.lineWidth = 20 // set the line width
ctx_due.strokeStyle = 'red' // set the line color
ctx_due.rect(50, 25, 200, 100)

ctx_due.fillStyle = 'yellow' // set the fill color
ctx_due.fill()
ctx_due.stroke()


/// 
/// TRE
///

const tre = document.getElementById('tre')
const ctx_tre = tre.getContext('2d')

ctx_tre.beginPath()
ctx_tre.strokeStyle = 'blue'
ctx_tre.lineWidth = 15
ctx_tre.rect(100, 25, 100, 100)
ctx_tre.fillStyle = 'white'
ctx_tre.fill()
ctx_tre.stroke()

ctx_tre.beginPath()
ctx_tre.rect(130, 60, 35, 35)
ctx_tre.fill()
ctx_tre.stroke()

