
var xmlns = "http://www.w3.org/2000/svg";
var origine = {x: 0, y: 0};

function addEvent(element, event, func) {
	if (element.addEventListener) {
		element.addEventListener(event, func, false);
	} else {
		element.attachEvent('on' + event, func);
	}
}

function getAbs(pos) { return 35 + 70 * (pos.x + origine.x); }
function getOrd(pos) { return 35 + 70 * (pos.y + origine.y); }

function Position(x, y) {
	this.x = x;
	this.y = y;
}

function Cloister(id, pt, completion) {
	this.id = id;
	this.pts = [pt];
	this.completion = completion;
}

function City(id, pts, holes, crests) {
	this.id = id;
	this.pts = pts;
	this.holes = holes;
	this.crests = crests;
}

function Road(id, pts, holes) {
	this.id = id;
	this.pts = pts;
	this.holes = holes;
}

function Field(id, pts, holes, neighborCities, neighborCitiesCompleted) {
	this.id = id;
	this.pts = pts;
	this.holes = holes;
	this.neighborCities = neighborCities;
	this.neighborCitiesCompleted = neighborCitiesCompleted;
}

function createHighlight(type, o) {
	let svg = document.getElementById("grid");
	let g = document.createElementNS(xmlns, "g");
	g.id = type+"Highlight"+o.id;
	g.setAttributeNS(null, "class", type+"Highlight");
	
	for (let i = 0; i < o.pts.length; i++) {
		let rect = document.createElementNS(xmlns, "rect");
		rect.setAttributeNS(null, "x", -35);
		rect.setAttributeNS(null, "y", -35);
		rect.setAttributeNS(null, "transform", "translate("+getAbs(o.pts[i])+", "+getOrd(o.pts[i])+")");
		rect.setAttributeNS(null, "width", 70);
		rect.setAttributeNS(null, "height", 70);
		
		
		rect.setAttributeNS(null, "class", type+"HighlightRect");
		
		g.appendChild(rect);
	}
	
	svg.appendChild(g);
}

function showHighlight(type, o) {
	let e = document.getElementById(type+"Highlight"+o.id);
	if (e == undefined)
		createHighlight(type, o);
	else
		e.style.display = "block";
}

function unshowHighlight(type, o) {
	let e = document.getElementById(type+"Highlight"+o.id);
	if (e != undefined)
		e.parentNode.removeChild(e);
}

function createCloisterHighlight(o) { createHighlight("Cloister", o); }
function showCloisterHighlight(o) { showHighlight("Cloister", o); }
function unshowCloisterHighlight(o) { unshowHighlight("Cloister", o); }

function createCityHighlight(o) { createHighlight("City", o); }
function showCityHighlight(o) { showHighlight("City", o); }
function unshowCityHighlight(o) { unshowHighlight("City", o); }

function createRoadHighlight(o) { createHighlight("Road", o); }
function showRoadHighlight(o) { showHighlight("Road", o); }
function unshowRoadHighlight(o) { unshowHighlight("Road", o); }

function createFieldHighlight(o) { createHighlight("Field", o); }
function showFieldHighlight(o) { showHighlight("Field", o); }
function unshowFieldHighlight(o) { unshowHighlight("Field", o); }



