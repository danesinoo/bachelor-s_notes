<?php

include_once 'ApiBuilder.php';
include_once 'Api.php';
include_once 'Router.php';

class NewProject
{
	public function createProject($name, $description): string
	{
		return "Creating project with name $name and description $description";
	}
}

$new_proj_api = (new ApiBuilder())
	->setPath('/new_proj')
	->setMethod('POST')
	->setInputParams(['name', 'description'])
	->setLogicClass('NewProject')
	->setLogicMethod('createProject')
	->setErrorHandler(function ($error) {
		http_response_code(400);
		echo json_encode(['error' => $error]);
	})
	->setAuthHandler(function () {
		return true;
	})
	->createApi();

$router = new Router();

$router->addRoute($new_proj_api);


$router->handle($_SERVER['REQUEST_URI'], $_SERVER['REQUEST_METHOD']);
