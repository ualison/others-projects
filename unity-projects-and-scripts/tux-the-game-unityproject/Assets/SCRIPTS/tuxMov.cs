using UnityEngine;
using System.Collections;

//MOVIMENTAÇAO DO TUX

public class tuxMov : MonoBehaviour {
	public int velocidade;
	public int VelPulo;

	void Update () {
	    if(Input.GetKey(KeyCode.D))
			transform.Translate(Vector2.right * velocidade * Time.deltaTime);
		
		if (Input.GetKey (KeyCode.A)) 
			transform.Translate(-Vector2.right * velocidade * Time.deltaTime);
	
		if (Input.GetKey (KeyCode.Space)) {
			transform.Translate(Vector2.up * VelPulo * Time.deltaTime);

	   }
    }
}
