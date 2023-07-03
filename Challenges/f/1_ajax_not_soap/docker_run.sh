#!/bin/bash
docker run "$@" --rm -p "127.0.0.1:8085:80" --name "ajax_not_soap" -it "spritzers/ajax_not_soap"

      // For element with id='name', when a key is pressed run this function
      $('#name').on('keypress',function(){
        // get the value that is in element with id='name'
        var that = $('#name');
        $.ajax('webhooks/get_username.php',{
        }).done(function(data){ // once the request has been completed, run this function
            data = data.replace(/(\r\n|\n|\r)/gm,""); // remove newlines from returned data
            if(data==that.val()){ // see if the data matches what the user typed in
              that.css('border', '1px solid green'); // if it matches turn the border green
              $('#output').html('Username is correct'); // state that the user was correct
            }else{ // if the user typed in something incorrect
              that.css('border', ''); // set input box border to default color
              $('#output').html('Username is incorrect'); // say the user was incorrect
            }
          }
        );
      });
      // dito ^ but for the password input now
      $('#pass').on('keypress', function(){
        var that = $('#pass');
        $.ajax('webhooks/get_pass.php?username='+$('#name').val(),{
        }).done(function(data){
            data = data.replace(/(\r\n|\n|\r)/gm,"");
            if(data==that.val()){
              that.css('border', '1px solid green');
              $('#output').html(data);
            }else{
              that.css('border', '');
              $('#output').html('Password is incorrect');
            }
          }
        );
      });
    