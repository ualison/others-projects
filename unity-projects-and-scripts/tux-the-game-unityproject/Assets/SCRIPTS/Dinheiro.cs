using UnityEngine;
using System.Collections;

//SCRIPT DO DINHEIRO

public class Dinheiro : MonoBehaviour {
	public AudioClip somDin;

	void OnCollisionEnter2D(Collision2D col){

		if(col.gameObject.tag == "Player"){
			Destroy(gameObject);
			AudioSource.PlayClipAtPoint(somDin, new Vector2(transform.position.x, transform.position.y));
			gerencItens.Dinheiro +=100;

	}
}
			        }
