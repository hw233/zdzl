var GameRoute=Route.extend({routes:{"!game/validCode/":"validCode","!game/validCode/:isRandom":"validCode","!game/notOpen/:msg":"notOpen","!game/notOpen":"notOpen"},initialize:function(){this.$el=document.querySelector("#gameContainer")},beforeRoute:function(){this.$el.innerHTML="",document.body.scrollTop=0},validCode:function(){this.$el.innerHTML=template.render("validateCodeTpl",{}),document.querySelector("#topCon").style.minHeight="210px",this._setBottom(57,"topCon")},notOpen:function(t){t=t?decodeURIComponent(t):"该游戏尚未开服，您可以：",this.$el.innerHTML=template.render("notOpenTpl",{message:t})},_setBottom:function(t,e,n,o,i){e=e||"fixBox_a";var r=function(){document.getElementById(e)&&(document.getElementById(e).style.height=i?document.documentElement.clientHeight-t-28+"px":document.documentElement.clientHeight-t+"px")};r(),n&&n(),window.addEventListener("resize",r),window.addEventListener("showkeyboard",function(){window.removeEventListener("resize",r)}),window.addEventListener("hidekeyboard",function(){window.addEventListener("resize",r)})}});