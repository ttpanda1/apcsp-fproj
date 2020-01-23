<!DOCTYPE html>
<html>
  <head>
    <title>Form Input 2</title>
  </head>


  <body>
    <a href="fprj.html">Back to Cipher Page</a>

    <h1>Vigenere Cipher</h1>
    <p>You can Encrypt or decyrpt a message using the vigenere cipher.</p>

    <?php
       // define variables and set to empty values
       $arg1 = $arg2 = $arg3 = $output = $retc = "";

       if ($_SERVER["REQUEST_METHOD"] == "POST") {
         $arg1 = test_input($_POST["arg1"]);
         $arg2 = test_input($_POST["arg2"]);
	 $arg3 = test_input($_POST["arg3"]);
         exec("/usr/lib/cgi-bin/sp1a/vigenerecipher " . $arg1 . " " . $arg2 . " " . $arg3, $output, $retc); 
       }

       function test_input($data) {
         $data = trim($data);
         $data = stripslashes($data);
         $data = htmlspecialchars($data);
         return $data;
       }
    ?>

    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
      Encrypt/Decyrpt: <input type="text" name="arg1"><br>
      Key: <input type="text" name="arg2"><br>
      Message: <input type="text" name="arg3"><br>
      <br>
      <input type="submit" value="Go!">
    </form>

    <?php
       // only display if return code is numeric - i.e. exec has been called
       if (is_numeric($retc)) {
         echo "<h2>Your Input:</h2>";
         echo $arg1;
         echo "<br>";
         echo $arg2;
         echo "<br>";
         echo $arg3;
         echo "<br>";
       
         echo "<h2>Program Output (an array):</h2>";
         foreach ($output as $line) {
           echo $line;
           echo "<br>";
         }
       
         echo "<h2>Program Return Code:</h2>";
         echo $retc;
       }
    ?>
    
  </body>
</html>
