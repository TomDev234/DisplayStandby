//	HYPE.documents["DisplayStandby"]

(function(){(function m(){function k(a,b,c,d){var e=!1;null==window[a]&&(null==window[b]?(window[b]=[],window[b].push(m),a=document.getElementsByTagName("head")[0],b=document.createElement("script"),e=l,false==!0&&(e=""),b.type="text/javascript",""!=d&&(b.integrity=d,b.setAttribute("crossorigin","anonymous")),b.src=e+"/"+c,a.appendChild(b)):window[b].push(m),e=!0);return e}var l="DisplayStandby.hyperesources",f="DisplayStandby",g="displaystandby_hype_container";if(false==
!1)try{for(var c=document.getElementsByTagName("script"),a=0;a<c.length;a++){var d=c[a].src,b=null!=d?d.indexOf("/displaystandby_hype_generated_script.js"):-1;if(-1!=b){l=d.substr(0,b);break}}}catch(p){}c=null==navigator.userAgentData&&navigator.userAgent.match(/MSIE (\d+\.\d+)/);c=parseFloat(c&&c[1])||null;d=!0==(null!=window.HYPE_740F||null!=window.HYPE_dtl_740F)||false==!0||null!=c&&10>c;a=!0==d?"HYPE-740.full.min.js":"HYPE-740.thin.min.js";c=!0==d?"F":"T";
d=d?"":"";if(false==!1&&(a=k("HYPE_740"+c,"HYPE_dtl_740"+c,a,d),false==!0&&(a=a||k("HYPE_w_740","HYPE_wdtl_740","HYPE-740.waypoints.min.js","")),false==!0&&(a=a||k("Matter","HYPE_pdtl_740","HYPE-740.physics.min.js","")),a))return;d=window.HYPE.documents;if(null!=d[f]){b=1;a=f;do f=""+a+"-"+b++;while(null!=d[f]);for(var e=
document.getElementsByTagName("div"),b=!1,a=0;a<e.length;a++)if(e[a].id==g&&null==e[a].getAttribute("HYP_dn")){var b=1,h=g;do g=""+h+"-"+b++;while(null!=document.getElementById(g));e[a].id=g;b=!0;break}if(!1==b)return}b=[];b=[];e={};h={};for(a=0;a<b.length;a++)try{h[b[a].identifier]=b[a].name,e[b[a].name]=eval("(function(){return "+b[a].source+"})();")}catch(n){window.console&&window.console.log(n),e[b[a].name]=function(){}}c=new window["HYPE_740"+c](f,g,{"0":{p:1,n:"Display%20Icon.png",g:"11",t:"@1x"},"-1":{n:"PIE.htc"},"-2":{n:"blank.gif"}},
l,[],e,[{n:"Untitled Scene",o:"1",X:[0]}],[{o:"3",p:"600px",cA:false,Y:800,Z:500,L:[],c:"#FFF",bY:1,d:800,U:{},T:{kTimelineDefaultIdentifier:{q:false,z:0,i:"kTimelineDefaultIdentifier",n:"Main Timeline",a:[],f:30,b:[]}},bZ:180,O:["18","17","16"],n:"Untitled Layout","_":0,v:{"18":{aV:8,w:"DisplayStandby Help",x:"visible",a:317,Z:"break-word",y:"preserve",j:"absolute",r:"inline",b:16,yy:"nowrap",s:"Helvetica,Arial,Sans-Serif",z:1,aS:8,t:16,aT:8,k:"div",aU:8,G:"#000",H:"underline"},"17":{h:"11",p:"no-repeat",x:"visible",a:16,dB:"img",q:"100% 100%",j:"absolute",r:"inline",z:4,k:"div",b:82,d:181,c:225},"16":{aU:8,G:"#000",c:752,aV:8,r:"inline",d:171,s:"Helvetica,Arial,Sans-Serif",t:16,Z:"break-word",w:"DisplayStandby is a simple App to switch off the Monitors.<br>In the Tableview Information about your Monitors is displayed.<br>With the Slider and the Time-Edit you can set a Timeinterval, after which the Monitors are switched off, without Keyboard and Mouse Activity.<br>With the activate Checkbox you can enable and disable DisplayStandby.<br>With the Standby Button you can switch off the Monitors immediately.<br>By clicking on the Logo you can open the Website.<br>DisplayStandby is written in C++. The graphical Userinterface is designed with Qt. Program Data is saved in JSON format.<br><br>",j:"absolute",x:"visible",k:"div",y:"preserve",z:2,aS:8,aT:8,a:16,F:"left",b:308}}}],{},h,{},null,false,true,-1,true,true,false,true,true);d[f]=c.API;document.getElementById(g).setAttribute("HYP_dn",f);c.z_o(this.body)})();})();