var GameRoute=Route.extend({routes:{"!game/validCode/":"validCode","!game/validCode/:isRandom":"validCode","!game/notOpen/:msg":"notOpen","!game/notOpen":"notOpen"},initialize:function(){this.$el=document.querySelector("#gameContainer")},beforeRoute:function(){this.$el.innerHTML="",document.body.scrollTop=0},validCode:function(){this.$el.innerHTML=template.render("validateCodeTpl",{}),document.querySelector("#topCon").style.minHeight="210px",this._setBottom(57,"topCon")},notOpen:function(e){e=e?decodeURIComponent(e):"该游戏尚未开服，您可以：",this.$el.innerHTML=template.render("notOpenTpl",{message:e})},_setBottom:function(e,t,n,o,i){t=t||"fixBox_a";var r=function(){document.getElementById(t)&&(document.getElementById(t).style.height=i?document.documentElement.clientHeight-e-28+"px":document.documentElement.clientHeight-e+"px")};r(),n&&n(),window.addEventListener("resize",r),window.addEventListener("showkeyboard",function(){window.removeEventListener("resize",r)}),window.addEventListener("hidekeyboard",function(){window.addEventListener("resize",r)})}});