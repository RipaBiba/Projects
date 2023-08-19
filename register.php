<!--Root PHP start-->
<?php
    require('connection.php');
?>
<!--Root PHP end-->

<!--PHP start-->
<?php
	if(isset($_GET['user_first_name'])){
		$user_first_name =  $_GET['user_first_name']; 
		$user_last_name =  $_GET['user_last_name']; 
		$user_email =  $_GET['user_email']; 
		$user_role =  $_GET['user_role']; 
		$user_password =  $_GET['user_password']; 
		$user_confirm_password =  $_GET['user_confirm_password']; 

		$sql = "INSERT INTO `users`(`user_first_name`, `user_last_name`, `user_email`, `user_role`, `user_password`, `user_confirm_password`) 
		VALUES ('$user_first_name','$user_last_name','$user_email', '$user_role','$user_password','$user_confirm_password')";

		if ($conn->query($sql) == TRUE) {
			echo "New data inserted successfully!";
			header('location:login.php');
			die();
		} else {
			echo "Error: " . $sql . "<br>" . $conn->error;
		}
	}
?>
<!--PHP end-->

<!DOCTYPE html>
<html lang="en">

<head>

  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
  <meta name="description" content="">
  <meta name="author" content="">
  <link href="img/logo/logo2.jpg" rel="icon">
  <title>Health Mart - Register</title>
  <link href="vendor/fontawesome-free/css/all.min.css" rel="stylesheet" type="text/css">
  <link href="vendor/bootstrap/css/bootstrap.min.css" rel="stylesheet" type="text/css">
  <link href="css/ruang-admin.min.css" rel="stylesheet">
	
  <!-- CSS -->
	<link rel="stylesheet" href="css/min.css">
	<link rel="stylesheet" href="css/bootstrap.datetimepicker.css">
	<link rel="stylesheet" href="//cdn.datatables.net/1.10.7/css/jquery.dataTables.css">
	<link rel="stylesheet" href="//cdn.datatables.net/plug-ins/1.10.7/integration/bootstrap/3/dataTables.bootstrap.css">

    <!-- Ionicons -->
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/ionicons/2.0.1/css/ionicons.min.css">
  <!-- Theme style -->
  <link rel="stylesheet" href="css/AdminLTE.css">
  
</head>

<body class="bg-gradient-login">
  <!-- Register Content -->
  <div class="container-login">
    <div class="row justify-content-center">
      <div class="col-xl-10 col-lg-12 col-md-9 p-2 my-5">
        <div class="card shadow-sm my-5">
		<div class="card p-4" style="background:url(img/back_log3.jpg);">
            <div class="row">
              <div class="col-lg-12">
                <div class="login-form" style="background:transparent;">
                  <div class="text-center">
				  	      <h class="h2 text-gray-900 mb-4">Health Mart</h>
					        <hr>
                    <h1 class="h4 text-gray-900 mb-4">Register</h1>
                  </div>
                  <form class="user" action="<?php echo $_SERVER['PHP_SELF']; ?>" method="GET" style="color: black; font-size: larger;">
                    <div class="form-group d-grid gap-2 margin-bottom d-md-flex justify-content-md-center">
                      <label style="margin-right: 10px;flex-basis: min-content;">First Name</label>
                      <input type="text" name="user_first_name" class="form-control" id="exampleInputFirstName" placeholder="Enter First Name">
                    </div>
                    <div class="form-group d-grid gap-2 margin-bottom d-md-flex justify-content-md-center">
                      <label style="margin-right: 10px;flex-basis: min-content;">Last Name</label>
                      <input type="text" name="user_last_name" class="form-control" id="exampleInputLastName" placeholder="Enter Last Name">
                    </div>
                    <div class="form-group d-grid gap-2 margin-bottom d-md-flex justify-content-md-center">
                      <label style="margin-right: 10px;flex-basis: min-content;">Email</label>
                      <input type="email"  name="user_email" class="form-control" id="exampleInputEmail" aria-describedby="emailHelp"
                        placeholder="Enter Email Address">
                    </div>
                    <div class="form-group d-grid gap-2 margin-bottom d-md-flex justify-content-md-center">
                      <label style="margin-right: 10px;flex-basis: min-content;">Password</label>
                      <input type="password" name="user_password" class="form-control" id="exampleInputPassword" placeholder="Password">
                    </div>
                    <div class="form-group d-grid gap-2 margin-bottom d-md-flex justify-content-md-center">
                      <label style="margin-right: 10px;flex-basis: min-content;">Repeat Password</label>
                      <input type="password" name="user_confirm_password" class="form-control" id="exampleInputPasswordRepeat"
                        placeholder="Repeat Password">
                    </div>
					<div class="form-group d-grid gap-2 margin-bottom d-md-flex justify-content-md-center">
                      <label style="margin-right: 10px;flex-basis: min-content;">User Type</label>
					  	<select name="user_role" class="form-control" id="exampleInputUserType">
							<option value="user">User</option>
							<option value="admin">Admin</option>
						</select>
                    </div>
                    <div class="form-group d-grid gap-2 margin-bottom d-md-flex justify-content-md-center">
					<div class="d-grid gap-2 d-md-flex justify-content-md-center">
                      <button type="submit" class="btn btn-outline-info bg-gradient-light mb-1">Register</button>
					</div>
                    </div>
                    <!--<hr>
                    <a href="index.html" class="btn btn-google btn-block">
                      <i class="fab fa-google fa-fw"></i> Register with Google
                    </a>
                    <a href="index.html" class="btn btn-facebook btn-block">
                      <i class="fab fa-facebook-f fa-fw"></i> Register with Facebook
                    </a>-->
                  </form>
                  <hr>
				  <div class="text-center text-gray-900">
				  	Already have an account? <a class="font-weight-bold text-decoration-none text-primary" href="login.php">Login Now!</a>
                  </div>
                  <div class="text-center">
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
  <!-- Register Content -->
  <script src="vendor/jquery/jquery.min.js"></script>
  <script src="vendor/bootstrap/js/bootstrap.bundle.min.js"></script>
  <script src="vendor/jquery-easing/jquery.easing.min.js"></script>
  <script src="js/ruang-admin.min.js"></script>
</body>

</html>