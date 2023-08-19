<!--Root PHP start-->
<?php
    require('connection.php');
    session_start();
?>
<!--Root PHP end-->

<!--PHP start-->
<?php
	if(isset($_POST['user_email'])){
		$user_email =  $_POST['user_email']; 
		$user_password =  $_POST['user_password']; 

		$sql = "SELECT * FROM `users` WHERE user_email='$user_email' AND user_password='$user_password'";

		$query = $conn->query($sql);

		if (mysqli_num_rows($query) > 0) {

			$data = mysqli_fetch_array($query);

			$user_first_name = $data['user_first_name'];
			$user_last_name = $data['user_last_name'];
			$user_role = $data['user_role'];

			$_SESSION['user_first_name'] = $user_first_name;
			$_SESSION['user_last_name'] = $user_last_name;
			$_SESSION['user_role'] = $user_role;

			echo "Successfully Login!";
			header('location:index.php');
			die();
		} else {
			echo "Error........ \n Wrong Information!";
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
  <title>Health Mart - Login</title>
  <link href="vendor/fontawesome-free/css/all.min.css" rel="stylesheet" type="text/css">
  <link href="vendor/bootstrap/css/bootstrap.min.css" rel="stylesheet" type="text/css">
  <link href="css/ruang-admin.min.css" rel="stylesheet">
  <!-- Select2 -->
  <link href="vendor/select2/dist/css/select2.min.css" rel="stylesheet" type="text/css">
  <!-- Bootstrap DatePicker -->  
  <link href="vendor/bootstrap-datepicker/css/bootstrap-datepicker.min.css" rel="stylesheet" >
	
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
  <!-- Login Content -->
  <div class="container-login">
    <div class="row justify-content-center">
      <div class="col-xl-6 col-lg-12 col-md-9 my-5">
        <div class="card shadow-sm my-5">
          <div class="card p-2" style="background:url(img/background.jpg);">
            <div class="row mb-3 container-fluid">
              <div class="col-lg-12">
                <div class="login-form" style="background:transparent;">
                  <div class="text-center">
				  	<h class="h2 text-gray-900 mb-4">Health Mart</h>
					<hr>
                    <h1 class="h4 text-gray-900 mb-4">Login</h1>
                  </div>
                  <form class="user" action="<?php echo $_SERVER['PHP_SELF']; ?>" method="POST">
                    <div class="form-group d-grid gap-2 margin-bottom d-md-flex justify-content-md-center">
                      <input type="email" name="user_email" class="form-control" id="exampleInputEmail" aria-describedby="emailHelp"
                        placeholder="Enter Email Address">
                    </div>
                    <div class="form-group d-grid gap-2 margin-bottom d-md-flex justify-content-md-center">
                      <input type="password" name="user_password" class="form-control" id="exampleInputPassword" placeholder="Password">
                    </div>
                    <!--<div class="form-group">
                      <div class="custom-control custom-checkbox small" style="line-height: 1.5rem;">
                        <input type="checkbox" class="custom-control-input" id="customCheck">
                        <label class="custom-control-label" for="customCheck">Remember
                          Me</label>
                      </div>
                    </div>-->
					          <div class="d-grid gap-2 d-md-flex justify-content-md-center">
                      <button class="btn btn-outline-info bg-gradient-light mb-1">Login</button></div>
                    <!--<a href="index.html" class="btn btn-google btn-block">
                      <i class="fab fa-google fa-fw"></i> Login with Google
                    </a>
                    <a href="index.html" class="btn btn-facebook btn-block">
                      <i class="fab fa-facebook-f fa-fw"></i> Login with Facebook
                    </a>-->
                  </form>
                  <hr>
                  <div class="text-center text-gray-900">
				  	          Yet not registered? <a class="font-weight-bold text-decoration-none text-primary" href="register.php">Create an Account!</a>
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
  <!-- Login Content -->
  <script src="vendor/jquery/jquery.min.js"></script>
  <script src="vendor/bootstrap/js/bootstrap.bundle.min.js"></script>
  <script src="vendor/jquery-easing/jquery.easing.min.js"></script>
  <script src="js/ruang-admin.min.js"></script>
</body>

</html>