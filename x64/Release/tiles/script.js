
var xmlns = "http://www.w3.org/2000/svg";

function addEvent(element, event, func) {
	if (element.addEventListener) {
		element.addEventListener(event, func, false);
	} else {
		element.attachEvent('on'+event, func);
	}
}

var K = (function(K) {
	K.p = function(x,y){this.x=x;this.y=y};
	K.addSvg = function(idx,father){let svg=document.createElementNS(xmlns,"svg");svg.id=idx;father.appendChild(svg);return svg;}
	
	// 20180624
	K.showOneState20180624 = function(idx,s){
		let svg = K.addSvg(idx,document.body);
		printOneState20180729(idx,svg,s);
	};
	
	// 20180729
	K.addSection = function(idx,father){let s=document.createElement("section");s.id=idx;father.appendChild(s);return s;}
	K.addButton = function(idx,father,name,call){let s=document.createElement("button");s.id=idx;addEvent(s,"click",call);s.appendChild(document.createTextNode(name));father.appendChild(s);return s;};
	
	function printOneState20180729(idx,svg,s){
		svg.setAttributeNS(null, "width", (s.bounds.xmax-s.bounds.xmin+1)*70);
		svg.setAttributeNS(null, "height", (s.bounds.ymax-s.bounds.ymin+1)*70);
		svg.setAttributeNS(null, "version", "1.1");
		let title = document.createElementNS(xmlns, "title");
		title.appendChild(document.createTextNode("Grille"));
		svg.appendChild(title);
		for (let i = 0, l = s.tiles.length; i < l; i++) {
			let img = document.createElementNS(xmlns, "image");
			img.id = idx+"img"+i;
			img.setAttributeNS(null, "href", "tiles/" + s.tiles[i].name + ".png");
			img.setAttributeNS(null, "x", -35);
			img.setAttributeNS(null, "y", -35);
			img.setAttributeNS(null, "height", 70);
			img.setAttributeNS(null, "width", 70);
			img.setAttributeNS(null, "transform", "translate(" + (35 + 70 * (s.tiles[i].position.x - s.bounds.xmin)) + ", " + (35 + 70 * (s.tiles[i].position.y - s.bounds.ymin)) + ") rotate(" + (-90 * s.tiles[i].direction) + ", 0, 0)");
			svg.appendChild(img);
		}
		for (let i = 0, l = s.reachables.length; i < l; i++) {
			let rect = document.createElementNS(xmlns, "rect");
			rect.setAttributeNS(null, "height", 70);
			rect.setAttributeNS(null, "width", 70);
			rect.setAttributeNS(null, "x", 70 * (s.reachables[i].x - s.bounds.xmin));
			rect.setAttributeNS(null, "y", 70 * (s.reachables[i].y - s.bounds.ymin));
			rect.setAttributeNS(null, "class", "reachable");
			svg.appendChild(rect);
		}
	}
	
	function printSingleFollower(circle,fol,x,y) {
		if (fol.type == "monk") {
			circle.setAttributeNS(null, "cx", 0);
			circle.setAttributeNS(null, "cy", 0);
		/*} else if (fol.type == "farmer") {
			circle.setAttributeNS(null, "cx", 0);
			circle.setAttributeNS(null, "cy", 0);
		*/} else {
			switch(fol.direction) {
				case 0:
					circle.setAttributeNS(null, "cx", +35);
					circle.setAttributeNS(null, "cy", 0);
					break;
				case 1:
					circle.setAttributeNS(null, "cx", 0);
					circle.setAttributeNS(null, "cy", -35);
					break;
				case 2:
					circle.setAttributeNS(null, "cx", -35);
					circle.setAttributeNS(null, "cy", 0);
					break;
				case 3:
					circle.setAttributeNS(null, "cx", 0);
					circle.setAttributeNS(null, "cy", +35);
					break;
			}
		}
		
		
		circle.setAttributeNS(null, "r", 10);
		circle.setAttributeNS(null, "transform", "translate(" + (35 + 70 * x) + ", " + (35 + 70 * y) + ")");
		circle.setAttributeNS(null, "class", "followerPlayer"+fol.player);
	}
	
	function printFollowers20180729(idx,svg,followers,bounds){
		for (let i = 0, l = followers.length; i < l; i++) {
			if (followers[i].type != "none" && followers[i].type != "unknown") {
				let circle = document.createElementNS(xmlns, "circle");
				circle.id = idx+"fol"+i;
				printSingleFollower(circle,followers[i],followers[i].position.x - bounds.xmin,followers[i].position.y - bounds.ymin);
				svg.appendChild(circle);
			}
		}
	}
	
	K.states = {};
	
	function State(i, length, svg, idx) {
		this.svg = svg;
		this.current = i; // #(idx+"svgimg"+i).style.display = "none";
		this.length = length;
		this.idximg = idx+"img";
		this.idxfol = idx+"fol";
	};
	
	K.showLogState20180729 = function(idx, s, f){
		let section = K.addSection(idx,document.body);
		let svg = K.addSvg(idx+"svg",section);
		printOneState20180729(idx+"svg",svg,s);
		K.states[idx] = new State(s.tiles.length, s.tiles.length, svg, idx+"svg");
		
		if (f !== undefined)
			printFollowers20180729(idx+"svg",svg,f,s.bounds);
		
		K.addButton(idx+"buttonclear",section,"Clear",(function() {
			var state = K.states[idx];
			return function() {
				for (let i = 0; i < state.length; i++) {
					state.svg.getElementById(state.idximg+i).style.display="none";
					let fol = state.svg.getElementById(state.idxfol+i);
					if (fol)
						fol.style.display="none";
				}
				state.current = 0;
			};
		})());
		K.addButton(idx+"buttonshow",section,"Show",(function() {
			var state = K.states[idx];
			return function() {
				for (let i = 0; i < state.length; i++) {
					state.svg.getElementById(state.idximg+i).style.display="block";
					let fol = state.svg.getElementById(state.idxfol+i);
					if (fol)
						fol.style.display="block";
				}
				state.current = state.length;
			};
		})());
		K.addButton(idx+"buttonnext",section,"Next",(function() {
			var state = K.states[idx];
			return function() {
				if (state.current < state.length) {
					state.svg.getElementById(state.idximg+state.current).style.display="block";
					let fol = state.svg.getElementById(state.idxfol+state.current);
					if (fol)
						fol.style.display="block";
					state.current++;
				}
			};
		})());
		K.addButton(idx+"buttonprec",section,"Prec",(function() {
			var state = K.states[idx];
			return function() {
				if (state.current > 0) {
					state.current--;
					state.svg.getElementById(state.idximg+state.current).style.display="none";
					let fol = state.svg.getElementById(state.idxfol+state.current);
					if (fol)
						fol.style.display="none";
				}
			};
		})());
	};
	
	K.showTable20180817 = function(idx, colNames, rows) {
		let table = document.createElement("table");
		table.id = idx;
		// première ligne:
		let tr = document.createElement("tr");
		for (let i = 0; i < colNames.length; i++) {
			let th = document.createElement("th");
			th.appendChild(document.createTextNode(colNames[i]));
			tr.appendChild(th);
		}
		table.appendChild(tr);
		// lignes suivantes:
		for (let r = 0; r < rows.length; r++) {
			let tr = document.createElement("tr");
			for (let i = 0; i < colNames.length; i++) {
				let td = document.createElement("td");
				td.appendChild(document.createTextNode(rows[r][i]));
				tr.appendChild(td);
			}
			table.appendChild(tr);
		}
		document.body.appendChild(table);
	};
	
	return K;
})(K || {});





