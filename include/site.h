#include <Arduino.h>
    
String html = "<!DOCTYPE html>" +
        (String) "<html>" +
            "<head>" + 
                "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">"+
                "<link rel=\"icon\" href=\"data:,\">" + 
                "<style>" + 
                    ".container {" +
                    "position: center;" +
                    "}" +
                    "html {" +  
                        "" +
                        "font-size: 55px;" +
                        "font-family: Arial, Helvetica, sans-serif;" + 
                        "font-weight: bold;" +
                        "display: inline-block;" + 
                        "margin: 0px auto;" + 
                        "text-align: center;" +
                        "color : #ffde59;" +
                        "background-color: #000000;" +
                        
                    "}" + 
                    ".button1 {" + 
                        "background-color: rgb(16, 175, 16);" + 
                        "border: none;" + 
                        "color: white;" + 
                        "padding: 25px 35px;" + 
                        "text-decoration: none;" + 
                        "font-size: 50px;" + 
                        "margin: 10px;" + 
                        "cursor: pointer;" +
                        "border-radius: 12px;" +
                        "box-shadow: 0 4px 8px 0 rgb(13, 147, 13); " +
                    "}" + 
                    ".button2 {" +
                        "background-color: #ff0000;" +
                        "border: none;" + 
                        "color: white;" + 
                        "padding: 25px 35px;" + 
                        "text-decoration: none;" + 
                        "font-size: 50px;" + 
                        "margin: 10px;" + 
                        "cursor: pointer;" +
                        "border-radius: 12px;" +
                        "box-shadow: 0 4px 8px 0 #c70404; " +
                    "}" +
                    ".img {" +
                        "margin-top: auto;" +
                        "margin: auto;" +
                        "display: block;" +
                        "width: 100%;" +
                        "height: auto;" +
                        "opacity: 0.8;" +
                        "margin-bottom: 5px;" +
                    "}" +
            "</style>" +
        "</head>" + 
    "<body>" +
        "<html>ESCOTILHA</html>";

String linha01 = "<div class=""container"">";
String linha02 =    "<p> <a> <img src=""https://cdn-icons-png.flaticon.com/128/4063/4063885.png""> </a> </p>";
String linha03 = "</div>";

String img1 = linha01 + linha02 + linha03;

String linha04 = "<div class=""container"">";
String linha05 =    "<p> <a> <img src=""https://cdn-icons-png.flaticon.com/128/4063/4063938.png""> </a> </p>";
String linha06 = "</div>";

String img2 = linha04 + linha05 + linha06;