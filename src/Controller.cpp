#include "Controller.h"

//String Controller::webPage0 = "<!DOCTYPE html>\n<html>\n<head>\n<meta name=viewport content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n<style>body{margin:0;-webkit-touch-callout:none;-webkit-user-select:none;-khtml-user-select:none;-moz-user-select:none;-ms-user-select:none;user-select:none;overflow:hidden}#connectingPage{width:100vw;height:100vh;position:absolute;top:0;left:0;display:flex;background:white;z-index:1002;justify-content:center;align-items:center;flex-direction:column}#connectingPageSvg{width:150px;height:150px}#connectingPageText{font:bold 30px sans-serif}#connectingPageButton{font:bold 30px sans-serif;padding:15px;border-radius:200px;border:5px solid grey;color:white;background:#292929}#navBar{position:absolute;top:0;left:0;display:flex;justify-content:space-between;height:0;width:100vw}#fullscreen{height:80px;margin:10px;padding-left:36.88px;cursor:pointer;z-index:1003}#fullscreen path:nth-child(1){transform-origin:17.5% 17.5%;transition:.5s ease}#fullscreen path:nth-child(2){transform-origin:82.5% 17.5%;transition:.5s ease}#fullscreen path:nth-child(3){transform-origin:82.5% 82.5%;transition:.5s ease}#fullscreen path:nth-child(4){transform-origin:17.5% 82.5%;transition:.5s ease}.unfullscreen path:nth-child(1){transform:rotate3D(1,-1,0,180deg)}.unfullscreen path:nth-child(2){transform:rotate3D(1,1,0,180deg)}.unfullscreen path:nth-child(3){transform:rotate3D(1,-1,0,180deg)}.unfullscreen path:nth-child(4){transform:rotate3D(1,1,0,180deg)}#controller{height:80px;margin:10px;cursor:pointer;z-index:1001}#select{border-top:1vh solid black;height:fit-content;border-bottom:1vh solid black;max-height:98vh;overflow:auto;z-index:1001}#select div{padding:10px;font:bold 25px sans-serif;cursor:pointer;text-align:center;position:relative}#select div[status=free]{border:5px solid grey;background:grey;color:white}#select div[status=mine]{border:5px solid darkgreen;background:darkgreen;color:white}#select div[status=other]{border:5px solid darkred;background:darkred;color:white}#select div[status=free][selected=false]:hover{background:white;color:grey}#select div[status=mine][selected=false]:hover{background:white;color:darkgreen}#select div[status=other][selected=false]:hover{background:white;color:darkred}#select div[status=free][selected=true]{background:#292929}#select div[status=mine][selected=true]{background:#002500}#select div[status=other][selected=true]{background:#380000}#select div:after{border-top:1px solid white;border-bottom:1px solid white;content:\"\";position:absolute;top:-5px;left:-5px;bottom:-5px;right:-5px}#page{position:absolute;top:0;left:0;width:100vw;height:100vh}.controllerPage{width:100vw;height:100vh;position:absolute;top:0;left:0}.controllerPageOverlay{width:100vw;height:100vh;position:absolute;top:0;left:0;z-index:1000;justify-content:center;align-items:center}.controllerPageOverlayButton{padding:15px;font:bold 30px sans-serif;border-radius:200px}.controllerPageOverlayButton[status=free]{border:5px solid grey;background:#292929;color:white}.controllerPageOverlayButton[status=mine]{border:5px solid darkgreen;background:#002500;color:white}.controllerPageOverlayButton[status=other]{border:5px solid darkred;background:#380000;color:white}.controllerPageOverlayButton[status=free]:hover{background:white;color:grey}.controllerPageOverlayButton[status=mine]:hover{background:white;color:darkgreen}.controllerPageOverlayButton[status=other]:hover{background:white;color:darkred}.joystick{width:100px;height:100px;border:3px solid black;display:flex;padding:23px;margin:10px}.joystick div{width:40px;height:40px;border:3px solid black;margin:auto;position:relative}.joystick div:hover{background:#71bbff}</style>\n</head>\n<body>\n<div id=connectingPage>\n<svg id=connectingPageSvg viewBox=\"0 0 100 100\"><path fill=black d=\"M73,50c0-12.7-10.3-23-23-23S27,37.3,27,50 M30.9,50c0-10.5,8.5-19.1,19.1-19.1S69.1,39.5,69.1,50\"><animateTransform attributeName=transform type=rotate dur=1s from=\"0 50 50\" to=\"360 50 50\" repeatCount=\"indefinite\"/></path></svg>\n<div id=connectingPageText>Connecting...</div>\n<div id=connectingPageButton onclick={startWebSocket();}>Reconnect</div>\n</div>\n<div id=navBar>\n<svg id=controller onclick='{document.getElementById(\"select\").style.display=(document.getElementById(\"select\").style.display==\"none\")?\"block\":\"none\";}' viewBox=\"0 80 504.079 345\">\n<path style=fill:#324D5B d=\"M502.519,328.249c-11.815-91.372-61.046-191.015-63.015-195.348c-0.788-1.575-2.363-3.151-3.938-3.938l-7.483-3.151l-2.363-8.665c0-0.788-0.394-1.182-0.788-1.969c-0.394-0.788-5.514-10.634-19.692-16.148c-12.997-5.12-45.686-16.542-65.378-16.542c-6.695,0-12.209,1.182-15.754,3.938c-2.757,1.182-14.572,11.815-25.994,11.815h-94.523c-11.028,0-23.237-10.24-25.994-11.815c-3.938-2.757-9.058-3.938-15.754-3.938c-19.692,0-52.382,11.422-65.378,16.542c-14.178,5.514-19.298,15.36-19.692,16.148c-0.394,0.394-0.394,1.182-0.788,1.969l-2.363,9.058l-5.514,3.151c-1.575,0.788-2.757,1.969-3.545,3.545c-1.969,4.332-51.2,103.975-63.015,195.348c-4.332,34.265,0.394,59.471,14.572,75.618c13.785,15.36,31.902,17.723,39.385,17.723h5.908c10.24,0,24.812-7.877,72.862-59.471c4.726-5.12,8.271-7.877,10.634-10.24c7.089-7.089,21.662-9.452,32.295-9.452h150.449c10.634,0,25.6,2.363,32.295,9.452c2.363,2.363,5.908,5.12,10.634,10.24c48.049,51.594,62.622,59.471,72.862,59.471h5.908c7.089,0,25.6-1.969,39.385-17.723C502.125,387.72,506.851,362.12,502.519,328.249z\"/>\n<path style=fill:#1D323D d=\"M439.504,132.902c-0.788-1.575-2.363-3.151-3.938-3.938l-7.483-3.151l-2.363-8.665c0-0.788-0.394-1.182-0.788-1.969c-0.394-0.788-5.514-10.634-19.692-16.148c-12.997-5.12-45.686-16.542-65.378-16.542c-6.695,0-12.209,1.182-15.754,3.938c-2.757,1.182-14.572,11.815-25.994,11.815h-94.523c-11.028,0-23.237-10.24-25.994-11.815c-3.938-2.757-9.058-3.938-15.754-3.938c-19.692,0-52.382,11.422-65.378,16.542c-14.178,5.514-19.298,15.36-19.692,16.148c-0.394,0.394-0.394,1.182-0.788,1.969l-2.363,9.058l-5.514,3.151c-1.575,0.788-2.757,1.969-3.545,3.545c-0.394,1.182-4.726,9.058-10.24,22.055l36.628-18.511c51.988-24.812,70.498-10.634,72.074-9.452c1.182,1.575,8.271,11.028,25.206,27.569c16.148,16.148,23.631,18.511,26.782,18.511h69.317c3.545,0,11.028-2.757,26.388-18.511c16.542-16.542,23.631-25.6,24.812-27.569c1.969-1.575,21.268-16.148,76.012,11.422c-0.788-0.788,23.237,11.422,39.385,19.692C444.624,143.536,440.291,134.083,439.504,132.902z\"/>\n<path style=fill:#597583 d=\"M372.156,216.397c-7.483,0-13.785,6.302-13.785,13.785s6.302,13.785,13.785,13.785s13.785-6.302,13.785-13.785S379.639,216.397,372.156,216.397z M403.664,184.889c-7.483,0-13.785,6.302-13.785,13.785s6.302,13.785,13.785,13.785s13.785-6.302,13.785-13.785S411.147,184.889,403.664,184.889z M340.648,184.889c-7.483,0-13.785,6.302-13.785,13.785s6.302,13.785,13.785,13.785s13.785-6.302,13.785-13.785S348.131,184.889,340.648,184.889zM372.156,153.382c-7.483,0-13.785,6.302-13.785,13.785s6.302,13.785,13.785,13.785s13.785-6.302,13.785-13.785C385.94,159.683,379.639,153.382,372.156,153.382z\"/>\n<path style=fill:#B8C4CB d=\"M252.033,121.874c8.665,0,15.754,7.089,15.754,15.754c0,8.665-7.089,15.754-15.754,15.754c-8.665,0-15.754-7.089-15.754-15.754C236.279,128.963,243.368,121.874,252.033,121.874z\"/>\n<path style=fill:#4F6B79 d=\"M222.888,279.412H208.71v14.572c0,3.151-2.363,5.514-5.514,5.514h-12.603c-3.151,0-5.514-2.363-5.514-5.514v-14.572h-14.178c-3.151,0-5.514-2.363-5.514-5.514v-12.603c0-3.151,2.363-5.514,5.514-5.514h14.178v-14.178c0-3.151,2.363-5.514,5.514-5.514h12.603c3.151,0,5.514,2.363,5.514,5.514v14.178h14.178c3.151,0,5.514,2.363,5.514,5.514v12.603C228.402,277.049,226.039,279.412,222.888,279.412z\"/>\n<path style=fill:#2D4552 d=\"M299.294,228.212c21.662,0,39.385,17.723,39.385,39.385c0,21.662-17.723,39.385-39.385,39.385c-21.662,0-39.385-17.723-39.385-39.385C259.91,245.936,277.633,228.212,299.294,228.212z\"/>\n<path style=fill:#4F6B79 d=\"M299.294,240.028c15.36,0,27.569,12.209,27.569,27.569s-12.209,27.569-27.569,27.569c-15.36,0-27.569-12.209-27.569-27.569C271.725,252.631,283.934,240.028,299.294,240.028z\"/>\n<path style=fill:#2D4552 d=\"M126.002,157.32c21.662,0,39.385,17.723,39.385,39.385s-17.723,39.385-39.385,39.385s-39.385-17.723-39.385-39.385S104.34,157.32,126.002,157.32z\"/>\n<path style=fill:#4F6B79 d=\"M126.002,169.136c15.36,0,27.569,12.209,27.569,27.569s-12.209,27.569-27.569,27.569s-27.569-12.209-27.569-27.569C98.433,181.739,110.642,169.136,126.002,169.136z\"/>\n<path style=fill:#3F5966 d=\"M299.294,251.843c8.665,0,15.754,7.089,15.754,15.754s-7.089,15.754-15.754,15.754s-15.754-7.089-15.754-15.754S290.63,251.843,299.294,251.843z M126.002,180.951c8.665,0,15.754,7.089,15.754,15.754s-7.089,15.754-15.754,15.754s-15.754-7.089-15.754-15.754C110.248,188.04,117.337,180.951,126.002,180.951z\"/>\n</svg>\n<div id=select style=display:none></div>\n<svg id='fullscreen'onclick=document.documentElement.webkitRequestFullScreen() viewBox='0 0 1 1'><path d=M0,0H0.35V0.15H0.15V0.35H0Z></path><path d=M1,0H0.65V0.15H0.85V0.35H1Z></path><path d=M1,1H0.65V0.85H0.85V0.65H1Z></path><path d=M0,1H0.35V0.85H0.15V0.65H0Z></path></svg>\n</div>\n<script>document.onwebkitfullscreenchange=function()\n{var fullscreen=document.getElementById('fullscreen');if(document.webkitIsFullScreen){fullscreen.classList='unfullscreen';fullscreen.onclick=function(){document.webkitExitFullscreen();};}\nelse{fullscreen.classList='';fullscreen.onclick=function(){document.documentElement.webkitRequestFullScreen();};}}\nfunction run(code,element,message){eval(code);}\nvar webSocket;var controller=[];var selectedController=0;function startWebSocket()\n{document.getElementById('connectingPageSvg').style.display='block';document.getElementById('connectingPageText').style.display='block';document.getElementById('connectingPageButton').style.display='none';webSocket=new WebSocket('ws://'+window.location.hostname+':";
//String Controller::webPage1 = "/');webSocket.onmessage=function(a)\n{var parameter=a.data.split(',');var type=parseInt(parameter[0]);if(type==0)\n{controller=[];var oldControllerPage=document.getElementsByClassName('controllerPage');while(oldControllerPage.length>0)oldControllerPage[0].remove();document.getElementById('select').innerHTML='';var controllerCount=parseInt(parameter[1]);selectedController=0;for(var i=0;i<controllerCount;i++)\n{controller[i]={element:[],div:document.createElement('div'),divOverlay:document.createElement('div'),divOverlayButton:document.createElement('div'),selectOption:document.createElement('div')};controller[i].div.classList='controllerPage';if(selectedController!=i)controller[i].div.style.display='none';document.body.append(controller[i].div);controller[i].divOverlay.classList='controllerPageOverlay';controller[i].divOverlay.style.display='flex';controller[i].div.append(controller[i].divOverlay);controller[i].divOverlayButton.classList='controllerPageOverlayButton';controller[i].divOverlayButton.innerText='Take Controller';controller[i].divOverlayButton.setAttribute('status','free');controller[i].divOverlayButton.onclick=function()\n{webSocket.send('1,'+i);};controller[i].divOverlay.append(controller[i].divOverlayButton);if(parameter.length>(2+i))controller[i].selectOption.innerText=parameter[2+i];else controller[i].selectOption.innerText='Controller '+(i+1);if(i==selectedController)controller[i].selectOption.setAttribute('selected','true');else controller[i].selectOption.setAttribute('selected','false');controller[i].selectOption.setAttribute('status','free');controller[i].selectOption.onclick=function()\n{for(var i=0;i<controller.length;i++)\n{if(controller[i].selectOption!=this)\n{controller[i].selectOption.setAttribute('selected','false');controller[i].div.style.display='none';}\nelse\n{selectedController=i;controller[i].selectOption.setAttribute('selected','true');controller[i].div.style.display='block';}}};document.getElementById('select').append(controller[i].selectOption);}}\nelse if(type==1||type==2||type==3)\n{var controllerIndex=parseInt(parameter[1]);var elementIndex=parseInt(parameter[2]);var elementObject=controller[controllerIndex].element[elementIndex];var message=a.data.substring(a.data.indexOf(',',a.data.indexOf(',',a.data.indexOf(',')+1)+1)+1);if(type==1&&elementObject!=undefined)run(elementObject.update,elementObject.div,message);if(type==2&&elementObject!=undefined)\n{elementObject.div.remove();elementObject=undefined;}\nif(elementObject==undefined)\n{elementObject=controller[controllerIndex].element[elementIndex]={init:'',div:document.createElement('div'),update:''};elementObject.div.sendData=(data)=>webSocket.send('0,'+controllerIndex+','+elementIndex+','+data);controller[i].div.append(elementObject.div);}\nif(type==2)run(elementObject.init=message,elementObject.div);if(type==3)elementObject.update=message;}\nelse if(type==4||type==5||type==6)\n{var controllerIndex=parseInt(parameter[1]);if(type==4)controller[controllerIndex].selectOption.setAttribute('status','free');if(type==5)controller[controllerIndex].selectOption.setAttribute('status','other');if(type==6)controller[controllerIndex].selectOption.setAttribute('status','mine');if(type==4)controller[controllerIndex].divOverlay.firstElementChild.setAttribute('status','free');if(type==5)controller[controllerIndex].divOverlay.firstElementChild.setAttribute('status','other');if(type==6)controller[controllerIndex].divOverlay.firstElementChild.setAttribute('status','mine');if(type==4||type==5)controller[controllerIndex].divOverlay.style.display='flex';if(type==6)controller[controllerIndex].divOverlay.style.display='none';}}\nwebSocket.onopen=function()\n{document.getElementById('connectingPage').style.display='none';}\nwebSocket.onclose=function()\n{document.getElementById('connectingPage').style.display='flex';document.getElementById('connectingPageSvg').style.display='none';document.getElementById('connectingPageText').style.display='none';document.getElementById('connectingPageButton').style.display='block';}\nwebSocket.onerror=function()\n{}}\nstartWebSocket();webSocket.onmessage({data:'0,5'});</script>\n</body>\n</html>";

Controller::Controller(int count, int setPort) : webSocket(setPort)
{
	port = setPort;

	//webPage = webPage0 + String(port) + webPage1;
	//webPageC_Str = webPage.c_str();

	webSocket.onEvent([=](uint8_t num, WStype_t type, uint8_t * payload, size_t length){ webSocketEvent(num, type, payload, length); });
	webSocket.begin();

	for(int i = 0; i < count; i++)
	{
		singleController.push_back(new SingleController(i, this));
		singleControllerName.push_back("Controller " + String(i + 1));
	}
}

Controller::Controller(std::initializer_list<String> nameList, int setPort) : webSocket(setPort)
{
	port = setPort;

	//webPage = webPage0 + String(port) + webPage1;
	//webPageC_Str = webPage.c_str();

	webSocket.onEvent([=](uint8_t num, WStype_t type, uint8_t * payload, size_t length){ webSocketEvent(num, type, payload, length); });
	webSocket.begin();

	std::vector<String> nameVector(nameList);

	for(int i = 0; i < nameVector.size(); i++)
	{
		singleController.push_back(new SingleController(i, this));
		if(nameVector[i] == "") singleControllerName.push_back("Controller " + String(i + 1));
		else singleControllerName.push_back(nameVector[i]);
	}
}

const char* Controller::getWebPage()
{
	return webPageC_Str;
}

void Controller::update()
{
	webSocket.loop();
}

SingleController& Controller::operator[] (int index)
{
	return *singleController[index];
}

void Controller::webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length)
{
	/*Server-Sent
	0 - controllerCount (0 , count , [controllerName ,])
	1 - message (1 , controllerIndex , elementIndex , message)
	2 - initJs (2 , controllerIndex , elementIndex , initJs)
	3 - updateJs (3 , controllerIndex , elementIndex , updateJs)
	4 - noOwner (4 , controllerIndex)
	5 - yesOwner (5 , controllerIndex)
	6 - yourOwner (6 , controllerIndex)
	*/
	/*Client-Sent
	0 - message (0 , controllerIndex , elementIndex , message)
	1 - takeController (1 , controllerIndex)
	*/

	if (type == WStype_CONNECTED)
	{
		String controllerMessage = "0," + String(singleController.size());
		for(int c = 0; c < singleController.size(); c++) controllerMessage += "," + singleControllerName[c];
		webSocket.sendTXT(num, controllerMessage);

		for(int c = 0; c < singleController.size(); c++)
		{
			if(singleController[c]->hasOwner == true) webSocket.sendTXT(num, "5," + String(c));
			else webSocket.sendTXT(num, "4," + String(c));

			for(int e = 0; e < singleController[c]->element.size(); e++)
			{
				webSocket.sendTXT(num, "2," + String(c) + "," + String(e) + "," + String(singleController[c]->element[e]->initJs));
				webSocket.sendTXT(num, "3," + String(c) + "," + String(e) + "," + String(singleController[c]->element[e]->updateJs));
				singleController[c]->element[e]->connected(num);
			}
		}
	}
	else if (type == WStype_DISCONNECTED)
	{
		for(int c = 0; c < singleController.size(); c++)
		{
			if(singleController[c]->hasOwner && singleController[c]->owner == num)
			{
				singleController[c]->hasOwner = false;
				webSocket.broadcastTXT("4," + String(c));
			}

			for(int e = 0; e < singleController[c]->element.size(); e++)
			{
				singleController[c]->element[e]->disconnected(num);
			}
		}
	}
	else if (type == WStype_TEXT)
	{
		if(length == 0) return;
		char *message = (char*)malloc(length + 1);
		for (int i = 0; i < length; i++) message[i] = payload[i];
		message[length] = '\0';

		char *nextNumber = message;

		int messageType = strtol(nextNumber, &nextNumber, 10);
		nextNumber++;

		if(messageType == 0)
		{
			if (nextNumber == NULL) return;
			int controllerIndex = strtol(nextNumber, &nextNumber, 10);
			nextNumber++;

			if(!singleController[controllerIndex]->hasOwner || singleController[controllerIndex]->owner != num) return;

			if (nextNumber == NULL) return;
			int elementIndex = strtol(nextNumber, &nextNumber, 10);
			nextNumber++;

			if(elementIndex < singleController[controllerIndex]->element.size() && elementIndex >= 0)
			{
				singleController[controllerIndex]->element[elementIndex]->data(num, String(nextNumber));
			}
		}
		else if(messageType == 1)
		{
			if (nextNumber == NULL) return;
			int controllerIndex = strtol(nextNumber, &nextNumber, 10);
			nextNumber++;

			//if(singleController[controllerIndex]->hasOwner && singleController[controllerIndex]->owner == num) return;

			singleController[controllerIndex]->hasOwner = true;
			singleController[controllerIndex]->owner = num;

			webSocket.broadcastTXT("5," + String(controllerIndex));
			webSocket.sendTXT(num, "6," + String(controllerIndex));
		}

		free(message);
	}
}