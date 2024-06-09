<?php

class Api
{
	private $path;
	private $method;
	private $inputParams;
	private $logicClass;
	private $logicMethod;
	private $errorHandler;
	private $authHandler;

	public function __construct($path, $method, $inputParams, $logicClass, $logicMethod, $errorHandler, $authHandler)
	{
		$this->path = $path;
		$this->method = $method;
		$this->inputParams = $inputParams;
		$this->logicClass = $logicClass;
		$this->logicMethod = $logicMethod;
		$this->errorHandler = $errorHandler;
		$this->authHandler = $authHandler;
	}

	private function post($param)
	{
		$json = file_get_contents("php://input");

		$data = json_decode($json, true);
		if ($data !== null && isset($data[$param])) {
			return $data[$param];
		} else if (isset($_POST[$param])) {
			return $_POST[$param];
		} else {
			return null;
		}
	}

	private function get($param)
	{
		$json = file_get_contents("php://get");

		$data = json_decode($json, true);
		if ($data !== null && isset($data[$param])) {
			return $data[$param];
		} else if (isset($_GET[$param])) {
			return $_GET[$param];
		} else {
			return null;
		}
	}

	private function getInputParams()
	{
		$params = [];
		if ($this->method === 'GET') {
			foreach ($this->inputParams as $param) {
				$params[] = $this->get($param) ?? null;
			}
		} else if ($this->method === 'POST') {
			foreach ($this->inputParams as $param) {
				$params[] = $this->post($param) ?? null;
			}
		}

		return $params;
	}

	private function response($result)
	{
		header('Content-Type: application/json');
		echo json_encode($result);
	}

	private function is_input_valid($input)
	{
		foreach ($input as $param) {
			if ($param === null) {
				return false;
			}
		}
		return true;
	}

	public function handle()
	{
		if (!call_user_func($this->authHandler)) {
			call_user_func($this->errorHandler, "Unauthorized");
			return;
		}
		$params = $this->getInputParams();
		if (!$this->is_input_valid($params)) {
			call_user_func($this->errorHandler, "Invalid input");
			return;
		}
		try {
			$logicInstance = new $this->logicClass();
			$result = call_user_func_array([$logicInstance, $this->logicMethod], $params);
			$this->response($result);
		} catch (Exception $e) {
			call_user_func($this->errorHandler, $e->getMessage());
		}
	}

	public function match($path, $method): bool
	{
		return $this->path === $path && $this->method === $method;
	}
}
