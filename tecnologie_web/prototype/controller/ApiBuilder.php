<?php

include_once 'Api.php';

class ApiBuilder
{
	private $path;
	private $method;
	private $inputParams;
	private $logicClass;
	private $logicMethod;
	private $errorHandler;
	private $authHandler;

	public function setPath($path)
	{
		$this->path = $path;
		return $this;
	}

	public function setMethod($method)
	{
		if (!in_array($method, ['GET', 'POST'])) {
			throw new Exception("Invalid method");
		}
		$this->method = $method;
		return $this;
	}

	public function setInputParams($inputParams)
	{
		$this->inputParams = $inputParams;
		return $this;
	}

	public function setLogicClass($logicClass)
	{
		$this->logicClass = $logicClass;
		return $this;
	}

	public function setLogicMethod($logicMethod)
	{
		$this->logicMethod = $logicMethod;
		return $this;
	}

	public function setErrorHandler($errorHandler)
	{
		$this->errorHandler = $errorHandler;
		return $this;
	}

	public function setAuthHandler($authHandler)
	{
		$this->authHandler = $authHandler;
		return $this;
	}

	public function createApi(): Api
	{
		if (empty($this->path) || empty($this->method) || empty($this->logicClass) || empty($this->logicMethod)) {
			throw new Exception("All necessary parameters must be set before creating the API");
		}

		return new Api($this->path, $this->method, $this->inputParams, $this->logicClass, $this->logicMethod, $this->errorHandler, $this->authHandler);
	}
}
